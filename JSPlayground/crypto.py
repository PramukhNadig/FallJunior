import codecs
import hashlib
def SHA_ENCODE(key,days):
    newKey = key
    for i in range(days):
        newKey = bytes.fromhex(hashlib.sha256(newKey).hexdigest()) + b'\x21' # concat 33 in hex which is 0x21
    return codecs.encode(newKey, "hex")
print(SHA_ENCODE(b'Youfoundthekey!congratulations!!!', 21))
print(SHA_ENCODE(b'Youfoundthekey!congratulations!!!', 24))

#Pramukh Nadig
#I pledge my honor that I've abided by the Stevens Honor Code