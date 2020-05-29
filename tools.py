concern = lambda :print("imported")

pad_to_8_digit = lambda dig : '0'*(8-len(dig))+dig

pad_to_4_digit = lambda digi : '0'*(4-len(digi))+digi

char_to_int = lambda ch: ord(ch)-48 if ord(ch) < 60 else ord(ch.lower())-87
#create an 8 bit for a single char

int_to_hex_character=lambda num: chr(48+num) if num <=9 else chr(87+num)

char_to_bin=lambda ch: pad_to_8_digit(bin(ord(ch))[2:])

def Etao_meter(ch):
    if ch.isalpha :
        ch=ch.lower()
        return 26-('etaoinshrdlucmfwypvbgkjqxz'.find(ch))        
    else:
        return 0

       
def hex_chr_to_bin(ch):
    num=ord(ch)
    if 47<num< 57:
        return pad_to_4_digit(bin(num-48)[2:])
    elif 64<num< 71:
        return pad_to_4_digit(bin(num-55)[2:])
    else:
        return pad_to_4_digit(bin(num-87)[2:])
 
def hex_str_to_bin(hex):
    str1=""
    for i in hex:
        str1=str1+hex_chr_to_bin(i)
    return str1
    
def str_to_bin(str_input):
    result_bin=''
    for i in str_input:
        result_bin=result_bin+char_to_bin(i)
    return result_bin

def xor_bytes(b1,b2): #returns a string
    temp=[ '0']*8
    for i in range(8):
        if b1[i]==b2[i]:
            temp[i]='0'
        else:
            temp[i]='1'
    return ''.join(temp)

def hamming_binary(binary_string_one, binary_string_two):
    h=0
    h=abs(len(binary_string_one) - len(binary_string_two))
    Len=min(len(binary_string_one),len(binary_string_two))
    for i in range(Len):
        if binary_string_one[i] != binary_string_two[i]:
            h=h+1
    return h

def repeating_xor(Plain, key):
    L=len(Plain)
    index=0
    Cipher=""
    for i in range(L):  
        result_bin=xor_bytes(char_to_bin(key[index]),char_to_bin(Plain[i]))
        # this gets the xor'd string of the two characters    
        Cipher=Cipher+int_to_hex_character(int(result_bin[0:4],2))
        Cipher=Cipher+int_to_hex_character(int(result_bin[4:],2))

        index=index+1
        index=index%len(key) # this is to achieve rotation over the key
    return (Cipher)

def text_string_to_binary(input_string):
    bs=''
    for i in range(len(input_string)):
        bs=bs+char_to_bin(input_string[i])
    return bs
        




