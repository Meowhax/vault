vault
=====

- Vault is a lightweight and simple C++ crypt library.
- Vault provides interface for ARC4.
- No dependencies.
- MIT licensed.

sample
------
```c++
#include <iostream>
#include <string>

#include "vault.hpp"

int main( int argc, const char **argv )
{
    std::string encrypted = vault::ARC4( "Hello world.", "my-password" );
    std::string decrypted = vault::ARC4( encrypted, "my-password" );

    std::cout << "ARC4 Encrypted text: " << encrypted << std::endl;
    std::cout << "ARC4 Decrypted text: " << decrypted << std::endl;

    return 0;
}
```
