solve_me_first :: (Num a) => a -> a -> a
solve_me_first a b = a + b

main = do
  a <- readLn
  b <- readLn
  let sum = solve_me_first a b
  print sum
