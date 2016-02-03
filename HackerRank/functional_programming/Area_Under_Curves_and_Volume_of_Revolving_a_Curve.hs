import Text.Printf (printf)

v :: Double -> [Int] -> [Int] -> Double
v x [] [] = 0.0
v x (aa:xa) (bb:xb) = (fromIntegral aa) * x ** bb + v x xa xb

area :: Double -> Double
area r = pi * r * r

get_sum :: [Double] -> Double
get_sum [] = 0.0
get_sum (x:xs) = x + get_sum xs

-- This function should return a list [area, volume].
solve :: Int -> Int -> [Int] -> [Int] -> [Double]
solve l r a b = --Complete this function--
 [
  get_sum [v x a b * 0.001 | x <- [(fromIntegral l), (fromIntegral l) + 0.001 .. (fromIntegral r)]],
  get_sum [area (v x a b) * 0.001 | x <- [(fromIntegral l), (fromIntegral l) + 0.001 .. (fromIntegral r)]]
 ]


--Input/Output.
main :: IO ()
main = getContents >>= mapM_ (printf "%.1f\n"). (\[a, b, [l, r]] -> solve l r a b). map (map read. words). lines
