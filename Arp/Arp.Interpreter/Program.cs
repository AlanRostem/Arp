using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Reflection;

namespace Arp.Interpreter
{
    internal class Program
    {
        static void Main(string[] args)
        {

            var code = File.ReadAllText("../../../TestFiles/functions.arp");

            var interpreter = new Interpreter();
            interpreter.InterpretArpCode(code);

            while (true) ;
        }
    }
}
