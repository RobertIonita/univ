using System;
using System.Security.Cryptography;

namespace democonsole
{
    class Program
    {
        private static void RSAComputationalCost(int size)
        {
            RSACryptoServiceProvider myRSA = new RSACryptoServiceProvider(size);
            System.Diagnostics.Stopwatch swatch = new System.Diagnostics.Stopwatch();
            AesManaged myAES = new AesManaged();
            int count = 1;
            byte[] RSAciphertext;
            byte[] plaintext;
            String time_consumed;
            swatch.Start();
            myAES.GenerateKey();
            RSAciphertext = myRSA.Encrypt(myAES.Key, true);
            plaintext = myRSA.Decrypt(RSAciphertext, true);
            swatch.Stop();
            time_consumed = (" " + (swatch.ElapsedTicks / (10 * count)).ToString() + " ms");
            SHA256Managed myHash = new SHA256Managed();
            Console.Write("A message: ");
            string firstMessage = Console.ReadLine();
            Console.Write("Anoteher message: ");
            string secondMessage = Console.ReadLine();
            byte[] signature;
            signature = myRSA.SignData(System.Text.Encoding.ASCII.GetBytes(firstMessage), myHash);
            bool verified;
            verified = myRSA.VerifyData(System.Text.Encoding.ASCII.GetBytes(secondMessage), myHash, signature);
            Console.WriteLine("Validation: " + verified.ToString());
            Console.WriteLine(time_consumed);
        }
        static void Main(string[] args)
        {
            int caseSwitch = 1;

            while (true)
            {
                Console.WriteLine("\nComputational cost of RSA evaluation");
                Console.WriteLine("0. Exit");
                Console.WriteLine("1. 1024 bit");
                Console.WriteLine("2. 2048 bit");
                Console.WriteLine("3. 3072 bit");
                Console.WriteLine("4. 4096 bit");
                Console.Write("Your choice: ");

                caseSwitch = Convert.ToInt16(Console.ReadLine());
                switch (caseSwitch)
                {
                    case 0:
                        System.Environment.Exit(1);
                        break;
                    case 1:
                        Program.RSA1024evaluation(1024);
                        break;
                    case 1:
                        Program.RSA1024evaluation(2048);
                        break;
                    case 1:
                        Program.RSA1024evaluation(3072);
                        break;
                    case 1:
                        Program.RSA1024evaluation(4096);
                        break;
                    default:
                        Console.WriteLine("Default case");
                        break;
                }
            }
        }
    }
}
