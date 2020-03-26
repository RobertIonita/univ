using System;
using System.Text;
using System.Security.Cryptography;

namespace democonsole
{
    class Program2
    {
        private static void DSAGenerateKey(int size)
        {
            AesManaged myAES = new AesManaged();
            System.Diagnostics.Stopwatch swatch = new System.Diagnostics.Stopwatch();
            int count = 100;

            swatch.Start();
            for (int i = count - 1; i >= 0; i--)
                myAES.GenerateKey();
            swatch.Stop();

            String time_consumed = (swatch.Elapsed.TotalMilliseconds).ToString() + " ms";
            Console.WriteLine("Generate key cost for " + size + ": " + time_consumed);
        }
        private static void DSASigning(int size)
        {
            DSACryptoServiceProvider myDSA = new DSACryptoServiceProvider(size);
            byte[] data = Encoding.ASCII.GetBytes("Hello, world");
            System.Diagnostics.Stopwatch swatch = new System.Diagnostics.Stopwatch();
            int count = 100;
            byte[] signature = null;

            swatch.Start();
            for (int i = count - 1; i >= 0; i--)
                signature = myDSA.SignData(data);

            swatch.Stop();

            bool verify = myDSA.VerifyData(data, signature);
            String time_consumed = (swatch.Elapsed.TotalMilliseconds).ToString() + " ms";
            Console.WriteLine("DSA signing cost for " + size + ": " + time_consumed);
        }
        private static void DSAValidate(int size)
        {
            DSACryptoServiceProvider myDSA = new DSACryptoServiceProvider(size);
            byte[] data = Encoding.ASCII.GetBytes("Hello, world");
            System.Diagnostics.Stopwatch swatch = new System.Diagnostics.Stopwatch();
            byte[] signature;
            int count = 100;
            signature = myDSA.SignData(data);

            swatch.Start();
            for (int i = count - 1; i >= 0; i--)
                myDSA.VerifyData(data, signature);

            swatch.Stop();

            String time_consumed = (swatch.Elapsed.TotalMilliseconds).ToString() + " ms";
            Console.WriteLine("DSA validating cost for " + size + ": " + time_consumed);
        }

        private static void DSAComputationalCost(int size)
        {

            DSACryptoServiceProvider myDSA = new DSACryptoServiceProvider(size);
            byte[] data = Encoding.ASCII.GetBytes("Hello, world");
            System.Diagnostics.Stopwatch swatch = new System.Diagnostics.Stopwatch();
            byte[] signature = null;
            int count = 100;

            swatch.Start();
            for (int i = count - 1; i >= 0; i--)
            {
                signature = myDSA.SignData(data);
                myDSA.VerifyData(data, signature);
            }

            swatch.Stop();

            String time_consumed = (swatch.Elapsed.TotalMilliseconds).ToString() + " ms";
            Console.WriteLine("DSA validating cost for " + size + ": " + time_consumed);
        }
        static void Main(string[] args)
        {
            int caseSwitch = 1;

            while (true)
            {
                Console.WriteLine("\nYou have some options: ");
                Console.WriteLine("0. Exit");
                Console.WriteLine("1. Cost of DSA key generation");
                Console.WriteLine("2. Cost of DSA signing");
                Console.WriteLine("3. Cost of DSA validation");
                Console.WriteLine("4. Total computational cost of DSA cryptosystem");
                Console.Write("Your choice: ");

                caseSwitch = Convert.ToInt16(Console.ReadLine());
                switch (caseSwitch)
                {
                    case 0:
                        System.Environment.Exit(1);
                        break;
                    case 1:
                        Console.WriteLine("Key generation time");
                        Program2.DSAGenerateKey(512);
                        Program2.DSAGenerateKey(640);
                        Program2.DSAGenerateKey(768);
                        Program2.DSAGenerateKey(768);
                        break;
                    case 2:
                        Program2.DSASigning(512);
                        Program2.DSASigning(640);
                        Program2.DSASigning(768);
                        Program2.DSASigning(768);
                        break;
                    case 3:
                        Program2.DSAValidate(512);
                        Program2.DSAValidate(640);
                        Program2.DSAValidate(768);
                        Program2.DSAValidate(768);
                        break;
                    case 4:
                        Program2.DSAComputationalCost(512);
                        Program2.DSAComputationalCost(640);
                        Program2.DSAComputationalCost(768);
                        Program2.DSAComputationalCost(768);
                        break;
                    default:
                        Console.WriteLine("Invalid option");
                        break;
                }
            }
        }
    }
}
