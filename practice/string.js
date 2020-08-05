///Check Exist String

function checkStringEsixt(s1, s2) {
    return(s1.includes(s2)) 
}

// s1 = "I love you"
// s2 = "love"
// s3 = "hate"

// console.log(checkStringEsixt(s1, s2));
// console.log(checkStringEsixt(s1, s3));

///Shorten String

function shortenString(s1) {
    if(s1.length <= 8) return s1;
    else {
        let s2 = "";
        for(i = 0; i < 8; i++) {
            s2 += s1[i];
        }
        s2 += "...";
        return s2;
    }
}

// s1 = 'Xin chao cac ban';
// console.log(shortenString(s1));

///Capitalize String

function capitalizeString(s) {
    let result = "";
    for(i = 0; i < s.length; i++) {
        if(i === 0 || s[i-1] === " ") {
            result += s[i].toUpperCase();
        }
        else {
            result += s[i].toLowerCase();
        }
    }
    return result;
}

// s1 = "heLLo wORld";
// console.log(capitalizeString(s1));

///Repeat String 

function repeatString(s) {
    let result = s + '-';
    result = result.repeat(10);
    result = result.slice(0, result.lastIndexOf('-'));
    return result;
}

// s = "a";
// console.log(repeatString(s));

function repeatString2(s, n) {
    let result = s + '-';
    result = result.repeat(n);
    result = result.slice(0, result.lastIndexOf('-'));
    return result;
}

// s = 'a';
// console.log(repeatString2(s, 5));

///Reverse String 

function reverseString(s) {
    let result = "";
    for(i = 0; i < s.length; i++) {
        result += s[s.length - i - 1];
    }
    return result;
}

// s = "A B C"
// console.log(reverseString(s));

///Check reverse String

function checkReverseString(s) {
    s = s.replace(/ /gi, '');
    s = s.toLowerCase();
    result = reverseString(s);
    return (result === s);
}

// s = "A B cba";
// console.log(checkReverseString(s));

