using Arp.Language;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Arp.Language
{
    public class TokenStringManager
    {
        private HashSet<string> _tokens = new HashSet<string>();

        public bool IsMatchedToken(string str)
        {
            foreach(string token in PossibleMatchedTokens(str))
            {
                if (str == token)
                {
                    return true;
                }
            }

            return false;
        }

        public List<string> PossibleMatchedTokens(string subStr)
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
            AddTokenString(Keywords.Break);
            AddTokenString(Keywords.Case);
            AddTokenString(Keywords.Catch);
            AddTokenString(Keywords.Const);
            AddTokenString(Keywords.Continue);
            AddTokenString(Keywords.Default);
            AddTokenString(Keywords.Do);
            AddTokenString(Keywords.Else);
            AddTokenString(Keywords.Enum);
            AddTokenString(Keywords.False);
            AddTokenString(Keywords.Finally);
            AddTokenString(Keywords.For);
            AddTokenString(Keywords.Function);
            AddTokenString(Keywords.If);
            AddTokenString(Keywords.Import);
            AddTokenString(Keywords.In);
            AddTokenString(Keywords.New);
            AddTokenString(Keywords.Null);
            AddTokenString(Keywords.Return);
            AddTokenString(Keywords.Switch);
            AddTokenString(Keywords.Table);
            AddTokenString(Keywords.This);
            AddTokenString(Keywords.Throw);
            AddTokenString(Keywords.True);
            AddTokenString(Keywords.Try);
            AddTokenString(Keywords.Var);
            AddTokenString(Keywords.While);
        }
    }
}
