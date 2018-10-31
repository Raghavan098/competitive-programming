{-
@EXPECTED_RESULTS@: CORRECT
-}

module Main where

main = interact (unlines . map show . run . tail . lines) where
    run []     = []
    run (x:xs) = let [n,m] = map read (words x)
                  in n - 1 : run (drop m xs)
