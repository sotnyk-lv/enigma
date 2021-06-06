plaintext = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'

r1 = 'EKMFLGDQVZNTOWYHXUSPAIBRCJ'
r2 = 'AJDKSIRUXBLHWTMCQGZNPYFVOE'
r3 = 'BDFHJLCPRTXVZNYEIWGAKMUSQO'
r4 = 'ESOVPZJAYQUIRHXLNFTGKDCMWB'
r5 = 'VZBRGITYUPSDNHLXAWMJQOFECK'
UKV_B = 'YRUHQSLDPXNGOKMIEBFZCWVJAT' 

r = 'FVPJIAOYEDRZXWGCTKUQSBNMHL'

r_pairs = []
for i in range(26):
    r_pairs.append((plaintext[i], r[i]))

r_pairs.sort(key=lambda x: x[1])


r_ = ''
for i in range(26):
    r_ += r_pairs[i][0]

print(r_)

nr = []
nr_ = []
for letter in r:
    nr.append(ord(letter)-ord("A"))

for letter in r_:
    nr_.append(ord(letter)-ord("A"))

print(nr)
print(nr_)
    
