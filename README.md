vault
=====

- Vault is a lightweight and simple C++ crypt library.
- Vault provides interface for ARC4.
- No dependencies.
- MIT licensed.

sample
------
<pre>
#include &lt;iostream&gt;
#include &lt;string&gt;

#include "vault.hpp"

int main( int argc, const char **argv )
{
    std::string encrypted = vault::ARC4( "Hello world.", "my-password" );
    std::string decrypted = vault::ARC4( encrypted, "my-password" );

    std::cout &lt;&lt; "ARC4 Encrypted text: " &lt;&lt; encrypted &lt;&lt; std::endl;
    std::cout &lt;&lt; "ARC4 Decrypted text: " &lt;&lt; decrypted &lt;&lt; std::endl;

    return 0;
}
</pre>
