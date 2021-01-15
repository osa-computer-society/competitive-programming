type Case = (Float, Float)

main :: IO ()
main = interact (solve . readInput)

readInput :: String -> [Case]
readInput s = map (readCase . words) (tail (lines s))

readCase :: [String] -> Case
readCase (a : b : _) = (fromIntegral $ read a, read b)

solve :: [Case] -> String
solve cases = unlines $ map solveCase cases

solveCase :: Case -> String
solveCase (b, p) = unwords $ map (show . (60 /)) [p / (b - 1), (p / b), p / (b + 1)]
