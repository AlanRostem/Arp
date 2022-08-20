﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ArpLanguage
{
    public class TokenStringManager
    {
        private HashSet<string> _tokens = new HashSet<string>();

        public List<string> PossibleTokenMatch(string subStr)
        {
            var list = new List<string>();
            foreach (var token in _tokens)
            {
                if (token.Contains(subStr))
                    list.Add(token);
            }
            return list;
        }

        protected void AddTokenString(string token)
        {
            if (!_tokens.Add(token))
            {
                Console.WriteLine("The token " + token + "has already been added.");
            }
        }
    }

    public class KeywordManager : TokenStringManager
    {
        public KeywordManager()
        {

        }
    }
}
