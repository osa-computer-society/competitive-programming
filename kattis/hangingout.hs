data Event = Enter Int | Leave Int

data Input = Input Int Int [Event]

main :: IO ()
main = interact ((++ "\n") . show . solve . readInput)

readInput :: String -> Input
readInput s = Input l x q
  where
    (f : r) = map words $ lines s
    (l : x : _) = map read f
    q = map readRow r

readRow :: [String] -> Event
readRow ("enter" : a : _) = Enter (read a)
readRow ("leave" : a : _) = Leave (read a)

solveRow :: Int -> (Int, Int) -> Event -> (Int, Int)
solveRow l (acc, cnt) (Enter x)
  | acc + x > l = (acc, cnt + 1)
  | otherwise = (acc + x, cnt)
solveRow l (acc, cnt) (Leave x) = (acc - x, cnt)

solve :: Input -> Int
solve (Input l x q) = b where (a, b) = foldl (solveRow l) (0, 0) q
