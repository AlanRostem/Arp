using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Arp.Language
{
    public class Token
    {
        public string Value { get; set; }
    }

    public class OpenCloseToken : Token
    {
        public bool IsClosing { get; set; }
    }
}
