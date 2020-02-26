char_to_int = lambda ch: ord(ch)-48 if ord(ch) < 60 else ord(ch.lower())-87
#create an 8 bit for a single char

padded_digit = lambda dig : '0'*(8-len(dig))+dig
pad_4 = lambda digi : '0'*(4-len(digi))+digi
File=open("File.txt")

Result_file=open("result.txt",'a+',encoding="utf-8")
# won't print unless encoding is set to utf 8
Result_file.truncate()
stat="etaoinshrdlcumwfgypbvkjxqz" #checking weight

def xor_bytes(b1,b2): #xors bytes of length 8 a list and returns a string
    temp=[ '0']*8
    for i in range(8):
        if b1[i]==b2[i]:
            temp[i]='0'
        else:
            temp[i]='1'
    return ''.join(temp)

counter =0
weight=0

for i in (File):  # iterates line by line 
    i=i[:-1]
    counter=counter+1
                 # the last char is enter 
    for k in range(127):        # iterates over each characters
        byte=""
        line=""
        weight=0
        for j in i:             # iterates for each character in a line              
            byte=byte+j 
                       
            if (len(byte) == 2):
                bin1=padded_digit(bin(k)[2:])
                bin2= pad_4(bin(char_to_int(byte[0]))[2:])+ pad_4(bin(char_to_int(byte[1]))[2:])                    
                val=int(xor_bytes(bin1,bin2),2)
                add =0
                if (stat.find(chr(val)) < 0) : 
                    add = 0
                else:
                    add= (len(stat)+1)-stat.find(chr(val))
                line=line+chr(val)  
                weight = weight + add                                      
                byte=""  
        
        if weight >300:
        # this step is to check which has the most weight and print it...i went checked weigths 100,200,...
            print( int(weight/100)*' ',line, weight,'  ', counter, chr(k)) # printing the character that the txt is encrypted with
            print(175*'*')
        





