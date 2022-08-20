using System;
using System.Collections.Generic;
using System.Linq;
using System.Text.RegularExpressions;
using System.Threading.Tasks;

namespace Arp.Interpreter
{
    public class CharValidator
    {
        private Regex _letterRegex;
        private Regex _numberRegex;
        private Regex _varcharRegex;

        public CharValidator()
        {
            _letterRegex = new Regex("[a-zA-Z]");
            _numberRegex = new Regex("[0-9]");
            _varcharRegex = new Regex("^[a-zA-Z_$][a-zA-Z_$0-9]*$");
        }

        public bool IsValidVarChar(char c)
        {
            return _varcharRegex.IsMatch(c.ToString());
        }

        public bool IsValidVarChar(string s)
        {
            return _varcharRegex.IsMatch(s);
        }
    }
}
