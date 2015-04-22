hello_worlds 0 = putStr ""
hello_worlds n = do
  putStr "Hello World\n"
  hello_worlds (n-1)

-- This part is related to the Input/Output and can be used as it is
-- Do not modify it
main = do
   n <- readLn :: IO Int
   hello_worlds n
