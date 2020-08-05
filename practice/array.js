///Find min

function min(arrNum) {
    let min = arrNum[0];
    arrNum.forEach(element => {
        if(min > element) min = element;
    });
    return min;
}

///Find second max

function max2nd(arrNum) {
    let max = arrNum[0], max2 = max;
    arrNum.forEach(element => {
        if(max < element) {
            max2 = max; 
            max = element;
        }
    })
    return max2;
}

function max(arrNum) {
    let max = arrNum[0]
    arrNum.forEach(element => {
        if(max < element) {
            max = element;
        }
    })
    return max;
}

// arr = [1, 2, 3, 4, 5];
// console.log(min(arr), max2nd(arr));

///Sort Students

function sortStudents(arrString) {
    for(i = 0; i < arrString.length - 1; i++) {
        for(j = i + 1; j < arrString.length; j++) {
            if(arrString[i] < arrString[j]) {
                temp = arrString[i];
                arrString[i] = arrString[j];
                arrString[j] = temp;
            }
        }
    }
    return arrString;
}

// arr = ['Hoa', 'Anh', 'Nam', 'Zung']
// console.log(sortStudents(arr));

///Sum 
function sum(min, max, modul) {
    // let temp = 0, sum = 0;
    // for(i = min; i <= max; i++) {
    //     if(i%modul === 0) {
    //         temp = i;
    //         break;
    //     }
    // }
    // for(i = temp; i <= max; i += modul) {
    //     sum += i;
    // }
    // return sum;
    let i = min + modul - min%modul;
    let j = max - max%modul;
    let count = (max - min)/modul + 1;
    return  (max + min)*count/2;
}

// console.log(sum(0, 100, 5));

function module(arrNum, mod) {
    let arrMod = [];
    arrNum.forEach(element => {
        arrMod.push(element%mod);
    });
    return arrMod;
}

// console.log(module([1, 2, 3], 2));

function arrMax(arrString) {
    let arrLength = [];
    let result = [];
    arrString.forEach(element => {
        arrLength.push(element.length);
    });
    let num = max(arrLength);
    arrString.forEach(element => {
        if(num === element.length) result.push(element);
    });
    return result;
}

console.log(arrMax(['asv', 'a', '', '  asd ', 'a b cd']));
