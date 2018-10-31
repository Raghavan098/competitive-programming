using System;
using System.Collections.Generic;

//
/*
 * @EXPECTED_RESULTS@: CORRECT
 * Time: O(n) -ish
 * 
 */

namespace SpyCamera
{
    internal class Program
    {
        private static void Main(string[] args)
        {
            System.Threading.Thread.CurrentThread.CurrentCulture = System.Globalization.CultureInfo.InvariantCulture;
            int n = int.Parse(Console.ReadLine());
            while (n-- > 0)
                new Program();
        }

        private class Vector2
        {
            public Vector2(double x, double y)
            {
                X = x;
                Y = y;
            }

            public double X, Y;
        }

        public Program()
        {
            int numPoints = int.Parse(Console.ReadLine());
            List<Vector2> roomGeom = new List<Vector2>();
            for (int i = 0; i < numPoints; i++)
            {
                string[] ss = Console.ReadLine().Split();
                roomGeom.Add(new Vector2(int.Parse(ss[0]), int.Parse(ss[1])));
            }
            double roomArea = CalcConvexArea(roomGeom);
            Vector2 cameraPos = new Vector2((roomGeom[0].X + roomGeom[1].X)/2, (roomGeom[0].Y + roomGeom[1].Y)/2);

            roomGeom.Insert(1, new Vector2(cameraPos.X, cameraPos.Y));

            // translate all points so camera goes to origin
            foreach (var v in roomGeom)
            {
                v.X -= cameraPos.X;
                v.Y -= cameraPos.Y;
            }

            // Rotate counterclockwise so that the "right camera edge" lies on the x-axis

            // Calculate angle between camera wall and x-axis
            double theta = Math.Atan2(roomGeom[2].Y, roomGeom[2].X);

            // Rotate by -theta
            // alpha = -theta
            double alpha = -theta;
            double sinAlpha = Math.Sin(alpha);
            double cosAlpha = Math.Cos(alpha);
            foreach (var v in roomGeom)
            {
                double xx = v.X*cosAlpha - v.Y*sinAlpha;
                double yy = v.X*sinAlpha + v.Y*cosAlpha;
                v.X = xx;
                v.Y = yy;
            }
            // Now the camera points 'up'

            // Now rotate everything clockwise by PI / 4
            alpha = -Math.PI/4;
            sinAlpha = Math.Sin(alpha);
            cosAlpha = Math.Cos(alpha);
            foreach (var v in roomGeom)
            {
                double xx = v.X*cosAlpha - v.Y*sinAlpha;
                double yy = v.X*sinAlpha + v.Y*cosAlpha;
                v.X = xx;
                v.Y = yy;
            }

            // Set all Y values under Y = 0 to 0
            // Set all Y values under Y = 0 to 0
            for (int i = 0; i < roomGeom.Count; i++)
            {
                var v = roomGeom[i];
                if (v.Y < 0)
                {
                    // Find a point where Y = 0
                    if (roomGeom[(i + 1)%roomGeom.Count].Y > 0)
                    {
                        // Add point after
                        var nextPoint = roomGeom[(i + 1)%roomGeom.Count];
                        double t = (-v.Y)/Math.Abs(nextPoint.Y - v.Y);
                        double newX = (nextPoint.X*(t) + v.X*(1 - t));
                        roomGeom.Insert(i + 1, new Vector2(newX, 0));
                    }
                    if (i == 0 && roomGeom[roomGeom.Count - 1].Y > 0)
                    {
                        // Add at the end
                        var nextPoint = roomGeom[roomGeom.Count - 1];
                        double t = (-v.Y)/Math.Abs(nextPoint.Y - v.Y);
                        double newX = (nextPoint.X*(t) + v.X*(1 - t));
                        roomGeom.Add(new Vector2(newX, 0));
                    }
                    if (i != 0 && roomGeom[i - 1].Y > 0)
                    {
                        // Add point before
                        var nextPoint = roomGeom[i - 1];
                        double t = (-v.Y)/Math.Abs(nextPoint.Y - v.Y);
                        double newX = (nextPoint.X*(t) + v.X*(1 - t));
                        roomGeom.Insert(i, new Vector2(newX, 0));
                        continue;
                    }
                    v.Y = 0;
                }
            }

            // Now rotate everything counterclockwise by PI / 2
            alpha = Math.PI/2;
            sinAlpha = Math.Sin(alpha);
            cosAlpha = Math.Cos(alpha);
            foreach (var v in roomGeom)
            {
                double xx = v.X*cosAlpha - v.Y*sinAlpha;
                double yy = v.X*sinAlpha + v.Y*cosAlpha;
                v.X = xx;
                v.Y = yy;
            }

            // Set all Y values under Y = 0 to 0
            for (int i = 0; i < roomGeom.Count; i++)
            {
                var v = roomGeom[i];
                if (v.Y < 0)
                {
                    // Find a point where Y = 0
                    if (roomGeom[(i + 1)%roomGeom.Count].Y > 0)
                    {
                        // Add point after
                        var nextPoint = roomGeom[(i + 1)%roomGeom.Count];
                        double t = (-v.Y)/Math.Abs(nextPoint.Y - v.Y);
                        double newX = (nextPoint.X*(t) + v.X*(1 - t));
                        roomGeom.Insert(i + 1, new Vector2(newX, 0));
                    }
                    if (i == 0 && roomGeom[roomGeom.Count - 1].Y > 0)
                    {
                        // Add at the end
                        var nextPoint = roomGeom[roomGeom.Count - 1];
                        double t = (-v.Y)/Math.Abs(nextPoint.Y - v.Y);
                        double newX = (nextPoint.X*(t) + v.X*(1 - t));
                        roomGeom.Add(new Vector2(newX, 0));
                    }
                    if (i != 0 && roomGeom[i - 1].Y > 0)
                    {
                        // Add point before
                        var nextPoint = roomGeom[i - 1];
                        double t = (-v.Y)/Math.Abs(nextPoint.Y - v.Y);
                        double newX = (nextPoint.X*(t) + v.X*(1 - t));
                        roomGeom.Insert(i, new Vector2(newX, 0));
                        i--;
                        continue;
                    }
                    v.Y = 0;
                }
            }

            double visionArea = CalcConvexArea(roomGeom);
            Console.WriteLine("{0:0.000000}", visionArea/roomArea);
        }

        private double CalcConvexArea(List<Vector2> pointsCC)
        {
            double firstPart = 0;
            double secondPart = 0;
            for (int i = 0; i < pointsCC.Count - 1; i++)
            {
                firstPart += pointsCC[i].X*pointsCC[i + 1].Y;
                secondPart += pointsCC[i].Y*pointsCC[i + 1].X;
            }
            firstPart += pointsCC[pointsCC.Count - 1].X*pointsCC[0].Y;
            secondPart += pointsCC[pointsCC.Count - 1].Y*pointsCC[0].X;
            return 0.5*Math.Abs(firstPart - secondPart);
        }
    }
}
