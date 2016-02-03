rev [] = []
rev [x] = [x]
rev (x : xs) = rev[xs] ++ [x] 
