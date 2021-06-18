func romanToInt(s string) int {
    ret := 0
    table := map[string]int {"I": 1, "V": 5, "X": 10, "L":50, "C": 100, "D": 500, "M": 1000,}
    for idx, c := range s {
        C := string(c)
        if idx > 0 {
            if C == "V" {
                if string(s[idx - 1]) == "I" {
                    ret += 3
                    continue
                } 
            } else if C == "X" {
                if string(s[idx - 1]) == "I" {
                    ret += 8
                    continue
                } 
            } else if C == "L" {
                if string(s[idx - 1]) == "X" {
                    ret += 30
                    continue
                } 
            } else if C == "C" {
                if string(s[idx - 1]) == "X" {
                    ret += 80
                    continue
                } 
            } else if C == "D" {
                if string(s[idx - 1]) == "C" {
                    ret += 300
                    continue
                } 
            } else if C == "M" {
                if string(s[idx - 1]) == "C" {
                    ret += 800
                    continue
                } 
            }
        }
        ret += table[C]
    }    
    return ret
}