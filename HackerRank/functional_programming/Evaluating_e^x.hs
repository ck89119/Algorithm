s x 10 tmp = 0.0
s x n tmp = tmp * x / n + s x (n + 1) (tmp * x / n)

solve :: Double -> Double
solve x = 1 + s x 1 1

main :: IO ()
main = getContents >>= mapM_ print. map solve. map (read::String->Double). tail. words
