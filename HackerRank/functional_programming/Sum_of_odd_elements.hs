f [] = 0
f (x : xs)
  | x `mod` 2 == 0 = f xs
  | x `mod` 2 == 1 = f xs + x

-- This part handles the Input/Output and can be used as it is. Do not change or modify it.
main = do
   inputdata <- getContents
   putStrLn $ show $ f $ map (read :: String -> Int) $ lines inputdata
