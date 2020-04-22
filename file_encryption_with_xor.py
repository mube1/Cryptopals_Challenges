import sys

# takes plaintext file , and key on command line and encryptes with
# repeated xor 

Plain=open(sys.argv[1]).read()[:-1]
key=sys.argv[2]

Cipher=""
print(len(Plain),'\n',len(key))

char_to_int = lambda ch: ord(ch)-48 if ord(ch) < 60 else ord(ch.lower())-87

char_to_bin=lambda ch: padded_digit(bin(ord(ch))[2:])

def xor_bytes(b1,b2): 
    #xors bytes of length 8 a list and returns a string
    temp=[ '0']*8
    for i in range(8):
        if b1[i]==b2[i]:
            temp[i]='0'
        else:
            temp[i]='1'
    return ''.join(temp)

padded_digit = lambda dig : '0'*(8-len(dig))+ dig

int_to_hex_character=lambda num: chr(48+num) if num <=9 else chr(87+num)


L=len(Plain)
index=0
for i in range(L):  
    result_bin=xor_bytes(char_to_bin(key[index]),char_to_bin(Plain[i]))
    Cipher=Cipher+int_to_hex_character(int(result_bin[0:4],2))
    Cipher=Cipher+int_to_hex_character(int(result_bin[4:],2))

    index=index+1
    index=index%len(key) # this is to achieve rotation over the key


print(Cipher)

cipher=open("encrypted"+open(sys.argv[1]).name,'a+')
cipher.write(Cipher)
cipher.close()



