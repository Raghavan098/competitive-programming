{-
    @EXPECTED_RESULTS@: CORRECT
-}

module Main where

import qualified Data.Map as M

main = interact (unlines . map show . run . tail . lines) where
    run []     = []
    run (x:xs) = let (xs1,xs2) = splitAt (read x) xs
                  in testcase xs1 : run xs2

testcase = subtract 1 . product . M.elems . M.map (+1)
           . foldr (\x -> M.insertWith (const (1+)) (words x !! 1) 1) M.empty
