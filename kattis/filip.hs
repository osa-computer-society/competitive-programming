solve :: [String] -> Int
solve (x : y : _) = max (read (reverse x)) (read (reverse y))

main :: IO ()
main = interact ((++ "\n") . show . solve . words)