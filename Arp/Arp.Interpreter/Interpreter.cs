using Arp.Language;
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

        int _i;

        private TokenExpectMode _currentExpectMode;
        private TokenMatcher _tokenMatcher;

        public Interpreter()
        {
            _currentExpectMode = TokenExpectMode.WORD;
            _tokenMatcher = new TokenMatcher();
        }

        public void InterpretArpCode(string code)
        {
            for (_i = 0; _i < code.Length; _i++)
            {
                switch (_currentExpectMode)
                {
                    case TokenExpectMode.ANYTHING:
                        break;
                    case TokenExpectMode.WORD:
                        ExpectWord(code);
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

        private void ExpectWord(string code)
        {
            bool isVarChar = _tokenMatcher.IsValidVarChar(code[_i]);
            if (!isVarChar)
            {
                // printf("Incorrect expect start: %c\n", code[i]);
                return;
            }

            // Count the word size
            var currentWordSize = 0;
            while (isVarChar)
            {
                currentWordSize++;
                isVarChar = _tokenMatcher.IsValidVarChar(code[_i + currentWordSize]);
            }

            var word = "";

            for (int j = 0; j < currentWordSize; j++)
            {
                word += code[j + _i];
            }

            string possibleKeyword = Keywords.Var;
            if (word == possibleKeyword)
            {
                Console.WriteLine("Found a keyword in the code: " + word);
            }

            _i += currentWordSize;
        }
    }
}
