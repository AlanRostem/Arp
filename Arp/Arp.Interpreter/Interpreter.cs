using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Arp.Interpreter
{
    public class Interpreter
    {
        public enum TokenExpectMode
        {
            ANYTHING,
            WORD,
            EXPRESSION,
            STRING_LITERAL,
            NUMBER_LITERAL,
        }

        private TokenExpectMode _currentExpectMode;

        public Interpreter()
        {
            _currentExpectMode = TokenExpectMode.ANYTHING;
        }

        public void InterpretArpCode(string code)
        {
            Console.WriteLine(code);
            switch (_currentExpectMode)
            {
                case TokenExpectMode.ANYTHING:
                    break;
                case TokenExpectMode.WORD:
                    break;
                case TokenExpectMode.EXPRESSION:
                    break;
                case TokenExpectMode.STRING_LITERAL:
                    break;
                case TokenExpectMode.NUMBER_LITERAL:
                    break;
            }
        }
    }
}
