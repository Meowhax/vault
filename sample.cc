#include <cassert>
#include <iostream>
#include <string>

#include "vault.hpp"

int main( int argc, const char **argv )
{
    // sample
    std::string encrypted = vault::ARC4( "Hello world.", "my-password" );
    std::string decrypted = vault::ARC4( encrypted, "my-password" );

    std::cout << "ARC4 Encrypted text: " << encrypted << std::endl;
    std::cout << "ARC4 Decrypted text: " << decrypted << std::endl;

    // tests
    assert( vault::ARC4("hello world", "my key") != "hello world" );
    assert( vault::ARC4(vault::ARC4("hello world", "my key"), "my key") == "hello world" );

    return 0;
}
