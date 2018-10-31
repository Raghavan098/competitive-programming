using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

// @EXPECTED_RESULTS@: CORRECT


namespace BAPC
{
    internal class Spy
    {
        public string Name;
        public string RentedCar = null;
        public bool Inconsistent = false;
        public long Damage;

        public Spy(string name)
        {
            Name = name;
        }

        public void ProcessPickup(string carName)
        {
            if (Inconsistent)
                return;
            if (RentedCar != null)
            {
                Inconsistent = true;
                return;
            }
            RentedCar = carName;
            Damage += Program.CarTypes[carName].Item2;
        }

        public void ProcessReturn(int kmDriven)
        {
            if (Inconsistent)
                return;
            if (RentedCar == null)
            {
                Inconsistent = true;
                return;
            }
            Damage += Program.CarTypes[RentedCar].Item3 * kmDriven;
            RentedCar = null;
        }

        public void ProcessAccident(float damage)
        {
            if (Inconsistent)
                return;
            if (RentedCar == null)
            {
                Inconsistent = true;
                return;
            }
            Damage += (int)Math.Ceiling(Program.CarTypes[RentedCar].Item1 * damage/100f);
        }
    }

    internal class Program
    {
        public static Dictionary<string, Tuple<int, int, int>> CarTypes; // name -> (price, pick up cost, cost/km)

        private static void Main(string[] args)
        {
            int tests = int.Parse(Console.ReadLine());
            while (tests-- > 0)
            {
                string[] ss = Console.ReadLine().Split();
                int numCarTypes = int.Parse(ss[0]);
                int numEvents = int.Parse(ss[1]);
                CarTypes = new Dictionary<string, Tuple<int, int, int>>();
                for (int i = 0; i < numCarTypes; i++)
                {
                    ss = Console.ReadLine().Split();
                    CarTypes.Add(ss[0], Tuple.Create(int.Parse(ss[1]), int.Parse(ss[2]), int.Parse(ss[3])));
                }

                Dictionary<string, Spy> spies = new Dictionary<string, Spy>();

                for (int i = 0; i < numEvents; i++)
                {
                    ss = Console.ReadLine().Split();
                    int time = int.Parse(ss[0]);
                    string spyName = ss[1];
                    char action = ss[2][0];

                    Spy spy = null;
                    if (spies.ContainsKey(spyName))
                        spy = spies[spyName];
                    else
                    {
                        spy = new Spy(spyName);
                        spies.Add(spyName, spy);
                    }

                    switch (action)
                    {
                        case 'p':
                            string carName = ss[3];
                            spy.ProcessPickup(carName);
                            break;
                        case 'r':
                            int kmDriven = int.Parse(ss[3]);
                            spy.ProcessReturn(kmDriven);
                            break;
                        case 'a':
                            int damage = int.Parse(ss[3]);
                            spy.ProcessAccident(damage);
                            break;
                    }
                }

                var spyList = spies.Values.ToList();
                spyList.Sort((a, b) => a.Name.CompareTo(b.Name));

                foreach (var spy in spyList)
                {
                    Console.WriteLine("{0} {1}", spy.Name,
                                                    spy.Inconsistent || spy.RentedCar != null ? "INCONSISTENT" : spy.Damage.ToString());
                }
            }
        }
    }
}
