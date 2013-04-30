/*
 * Vault is a lightweight and simple crypt library.
 * Copyright (c) 2013 Mario 'rlyeh' Rodriguez

 * Contains portions of ARC4 algorithm VBA implementation
 * Copyright (c) 2000, Mike Shaffer. All rights reserved.

 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.

 * To do:
 * - provide more crypting/decrypting algorithms

 * - rlyeh ~~ listening to Black Belt - Leeds
 */

#include <string>

#include "vault.hpp"

namespace vault
{
    namespace swap
    {
        std::string ARC4( const std::string &text, const std::string &passkey )
        {
            // Original VBA code by Mike Shaffer
            // http://www.4guysfromrolla.com/webtech/code/rc4.inc.html

            int sbox[256], key[256];

            size_t ilen = passkey.size();

            if( !ilen )
                return text;

            for( int a = 0; a < 256; a++ )
            {
                key[a] = passkey[a % ilen];
                sbox[a] = a;
            }

            for( int a = 0, b = 0; a < 256; a++ )
            {
                b = (b + sbox[a] + key[a]) % 256;
                std::swap(sbox[a], sbox[b]);
            }

            std::string output;
            output.resize( text.size() );

            for( int a = 0, i = 0, j = 0, iTextLen = text.size(), k; a < iTextLen; a++ )
            {
                i = (i + 1) % 256;
                j = (j + sbox[i]) % 256;
                std::swap(sbox[i], sbox[j]);
                k = sbox[(sbox[i] + sbox[j]) % 256];
                output[a] = text[a] ^ k;
            }

            return output;
        }
    }
}
