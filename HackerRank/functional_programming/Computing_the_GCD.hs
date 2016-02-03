module Main where


gcd' :: Integral a => a -> a -> a
gcd' 0 x = x
gcd' x 0 = x
gcd' x y = gcd' y (x `mod` y)

-- This part is related to the Input/Output and can be used as it is
-- Do not modify it
main = do
  input <- getLine
  print . uncurry gcd' . listToTuple . convertToInt . words $ input
 where
  listToTuple (x:xs:_) = (x,xs)
  convertToInt = map (read :: String -> Int)
