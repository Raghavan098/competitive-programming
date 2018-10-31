{-
    @EXPECTED_RESULTS@: CORRECT

    TODO: This can probably be done exactly.
-}
module Main where

import Data.List
import Numeric

main :: IO ()
main = interact (unlines . map (\f -> showFFloat (Just 6) f "") . run . tail . lines) where
    run []     = []
    run (x:xs) =
        let n         = read x
            (cs, xs') = splitAt n xs
            cs'       = map ((\[x,y] -> (fromInteger (read x)
                                        ,fromInteger (read y))) . words) cs
         in testcase n cs' : run xs'

testcase :: Int -> [Point] -> Double
testcase n cs@((x1,y1):(x2,y2):_) =
    let camera = ((x1 + x2) / 2, (y1 + y2) / 2)
        line1  = pointsToLine camera (rotatePointCCW (x1,y1) camera ( 1/4 * pi))
        line2  = pointsToLine camera (rotatePointCCW (x1,y1) camera (-1/4 * pi))

        walls  = adjacent (tail cs ++ [(x1,y1)])
        
        visibleWalls1 (w@(p1,p2):ws) =
            case lineLineIntersection line1 (pointsToLine p1 p2) of
                Nothing -> visibleWalls1 ws
                Just p  -> if not (pointOnLine' p p1 p2) then
                                visibleWalls1 ws
                           else
                                visibleWalls2 ((p,p2):ws)

        visibleWalls2 (w@(p1,p2):ws) =
            case lineLineIntersection line2 (pointsToLine p1 p2) of
                Nothing -> w : visibleWalls2 ws
                Just p  -> if not (pointOnLine' p p1 p2) then
                                w : visibleWalls2 ws
                           else
                                [(p1,p)]

        area (p1,p2) = areaOfTriangle p1 p2 camera
        
        visibleArea  = sum (map area (visibleWalls1 walls))
        totalArea    = sum (map area                walls )

     in visibleArea / totalArea
     
adjacent :: [a] -> [(a,a)]
adjacent [p1,p2]    = [(p1,p2)]
adjacent (p1:p2:ps) = (p1,p2) : adjacent (p2:ps)

-- | Geometry

type Angle = Double
type Point = (Double, Double)
type Line  = (Double, Double, Double)  -- Ax + By = C

infix 4 ~~

(~~) :: Double -> Double -> Bool
x ~~ y = abs (x - y) < epsilon
    where epsilon = 1e-8

between :: Double -> Double -> Double -> Bool
between x1 x x2
        | x1 <= x2 = x1 - epsilon <= x && x <= x2 + epsilon
        | x2 <= x1 = x2 - epsilon <= x && x <= x1 + epsilon
    where epsilon = 1e-8

pointsToLine :: Point -> Point -> Line
pointsToLine (x1,y1) (x2,y2) =
    let a = y2 - y1
        b = x1 - x2
        c = a * x1 + b * y1
     in (a, b, c)

lineLineIntersection :: Line -> Line -> Maybe Point
lineLineIntersection (a1, b1, c1) (a2, b2, c2) =
    let d = a1 * b2 - a2 * b1
     in if d ~~ 0 then
            Nothing
        else let x = (b2 * c1 - b1 * c2) / d
                 y = (a1 * c2 - a2 * c1) / d
              in Just (x, y)

pointOnLine :: Point -> Line -> Bool
pointOnLine (x, y) (a, b, c) = a * x + b * y ~~ c

pointOnLine' :: Point -> Point -> Point -> Bool
pointOnLine' p@(x,y) p1@(x1,y1) p2@(x2,y2) =
    pointOnLine p1 (pointsToLine p1 p2) && between x1 x x2 && between y1 y y2

rotatePointCCW :: Point -> Point -> Angle -> Point
rotatePointCCW (x,y) (x0, y0) theta =
    let x' = (x - x0) * cos theta - (y - y0) * sin theta
        y' = (x - x0) * sin theta + (y - y0) * cos theta
     in (x' + x0, y' + y0)

areaOfTriangle :: Point -> Point -> Point -> Double
areaOfTriangle (ax,ay) (bx,by) (cx,cy) =
    abs (ax * (by - cy) + bx * (cy - ay) + cx * (ay - by)) / 2
