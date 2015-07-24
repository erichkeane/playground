-- Haskell Solution for "FizzBuzz", though it doesn't print,
-- it only generates a list of the solution values.

fizzBuzzHelper :: Integral a => a -> [Char]
fizzBuzzHelper num
    | (num `mod` 3) == 0 && (num `mod` 5)==0 = "FizzBuzz"
    | (num `mod` 3) == 0 = "Fizz"
    | (num `mod` 5) == 0 = "Buzz"
    | otherwise = ""

fizzBuzz :: Integral a => [a] -> [(a, [Char])]
fizzBuzz  [] = []
fizzBuzz (x:xs) = (x,(fizzBuzzHelper x)):(fizzBuzz xs)
