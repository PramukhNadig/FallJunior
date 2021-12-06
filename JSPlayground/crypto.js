const { createHash } = require('crypto');


function hash(input){
    return createHash('sha256').update(input).digest('hex');
}

function encryptOTP(input, key){
    return input ^ key;
}

function decryptOTP(input, key){
    return input ^ key;
}



console.log(decryptOTP("2d0a0612061b0944000d161f0c1746430c0f0952181b004c1311080b4e07494852", "0D0A202020202020202020202020202020202020202020202020202020202020202020"));
