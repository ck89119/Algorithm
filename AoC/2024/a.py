import sys
import itertools

# each wire = [value, op, list(inputs), list(outputs), in_ready]
VALUE = 0
OP = 1
INPUTS = 2
OUTPUTS = 3
IN_READY = 4
wires = dict()
for l in sys.stdin:
    l = l.strip()
    if not l:
        continue
    if ":" in l:
        name, val = l.split(":")
        val = int(val)
        wires[name] = [val, None, [], [], 0]
    else:
        in1, op, in2, arrow, outw = l.split(" ")
        for w in (in1, in2, outw):
            if w not in wires:
                wires[w] = [None, None, [], [], 0]
        wires[outw][INPUTS] = [in1, in2]
        wires[outw][OP] = op
        wires[in1][OUTPUTS].append(outw)
        wires[in2][OUTPUTS].append(outw)

def findgates(wires, xwires, ywires, zwires, adder):
    xw = xwires[adder]
    yw = ywires[adder]
    zw = zwires[adder]
    HAS = None # Half adder sum
    HAC = None # Half adder carry
    CO = None # Carry out
    CI = None # Carry in
    CI0 = None # Carry intermediate
    OUT = None # Full adder output
    for w in wires[xw][OUTPUTS]:
        if set(wires[w][INPUTS]) == {xw, yw}:
            if wires[w][OP] == "XOR":
                HAS = w
            elif wires[w][OP] == "AND":
                HAC = w
    # Both HAS and HAC must exist, because we swap only outputs.
    for w in wires[HAS][OUTPUTS]:
        if wires[w][OP] == "XOR":
            OUT = w
            CI = list(set(wires[w][INPUTS]) - {HAS})[0]
    for w in wires[HAC][OUTPUTS]:
        if wires[w][OP] == "OR":
            CO = w
            CI0 = list(set(wires[w][INPUTS]) - {HAC})[0]
    # Promote the half-adder outputs
    if adder == 0 and not CO and not OUT:
        OUT = HAS
        CO = HAC
    
    return { "CI" : CI, "HAS" : HAS, "HAC" : HAC, "CI0": CI0, "OUT": OUT, "CO": CO}

def wswap(wires, s1, s2):
    swapped = set()
    for wo in itertools.chain(wires[s1][INPUTS], wires[s2][INPUTS]):
        if wo in swapped:
            continue
        no = []
        for wi in wires[wo][OUTPUTS]:
            if wi == s1:
                no.append(s2)
            elif wi == s2:
                no.append(s1)
            else:
                no.append(wi)
        wires[wo][OUTPUTS] = no
        swapped.add(wo)
    wires[s1][OUTPUTS], wires[s2][OUTPUTS] = wires[s2][OUTPUTS], wires[s1][OUTPUTS]
    wires[s1], wires[s2] = wires[s2], wires[s1]

xwires = list(filter(lambda x: x.startswith("x"), wires))
xwires.sort()
ywires = list(filter(lambda x: x.startswith("y"), wires))
ywires.sort()
zwires = list(filter(lambda x: x.startswith("z"), wires))
zwires.sort()
lastCO = None
okwires = set()
goodgates = set()

def isgatebad(wires, lastCO, xwires, ywires, zwires, i):
    gates = findgates(wires, xwires, ywires, zwires, i)
    bad = zwires[i] != gates["OUT"]
    bad = bad or (lastCO is not None and gates["CI"] != lastCO)
    if i:
        bad = bad or not gates["CI"]
    bad = bad or not gates["CO"] or (i > 0 and not gates["CI0"])
    lastCO = gates["CO"]
    return (bad, lastCO, gates)

for i in range(0, len(xwires)):
    (bad, lastCO, gates) = isgatebad(wires, lastCO, xwires, ywires, zwires, i)
    # Some gates may be good but the previous gate is bad.
    if not bad:
        okwires = okwires.union(filter(lambda x: x is not None, gates.values()))
        goodgates.add(i)
okwires = okwires.union(xwires)
okwires = okwires.union(ywires)
badwires = set(wires) - okwires
#print(badwires)
mustinclude = []
for w in badwires:
    if w in zwires and wires[w][OP] != "XOR":
        mustinclude.append(w)
#print(mustinclude)
otherbadwires = badwires.difference(mustinclude)
xorwires = set()
for w in otherbadwires:
    if wires[w][OP] == "XOR":
        xorwires.add(w)
comb = []
for xors in itertools.permutations(xorwires, len(mustinclude)):
    remains = otherbadwires.difference(xors)
    for rems in itertools.permutations(remains, 8 - len(xors) * 2):
        perm = xors + rems;
        swap = []
        for i, mi in enumerate(mustinclude):
            swap.append((mi, perm[i]))
        for i in range(len(mustinclude), len(perm), 2):
            swap.append((perm[i], perm[i+1]))
        comb.append(tuple(swap))
        
#print(len(comb))
for swi, tryswaps in enumerate(comb):
    lastCO = None
    bad = False
    for sw in tryswaps:
        wswap(wires, sw[0], sw[1])
    for i in range(0, len(xwires)):
        (bad, lastCO, gates) = isgatebad(wires, lastCO, xwires, ywires, zwires, i)
        if bad:
            break
    for sw in reversed(tryswaps):
        wswap(wires, sw[0], sw[1])
    #if (swi % 10000) == 0:
        #print(swi, len(comb), (swi * 100)/len(comb))
    if not bad:
        ans = list(itertools.chain.from_iterable(tryswaps))
        ans.sort()
        print(",".join(ans))
        break;
