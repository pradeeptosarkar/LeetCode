/**
 * @param {string[]} words
 * @return {number}
 */
var uniqueMorseRepresentations = function(words) {
    const morseCodes = [".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."];
    let morseWords = [];
    let word;

    for (let i = 0; i < words.length; i++) 
    {
        word = words[i].split('').map((c) => morseCodes[c.charCodeAt(0) - 97]).join('');
        
        if (morseWords.indexOf(word) === -1) 
        {
            morseWords.push(word);
        }
    }
    
    return morseWords.length;
};