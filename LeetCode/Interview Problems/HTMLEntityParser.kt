class Solution {
    fun entityParser(text: String): String {
        val sb = StringBuilder()
        var i = 0
        while(i < text.length){
            if(i + 6 <= text.length && text.substring(i, i+6) == "&quot;") {
                sb.append('\"')
                i += 6
            }
            else if(i + 6 <= text.length && text.substring(i, i+6) == "&apos;") {
                sb.append('\'')
                i += 6
            }
            else if(i + 5 <= text.length && text.substring(i, i+5) == "&amp;") {
                sb.append('&')
                i += 5
            }
            else if(i + 4 <= text.length && text.substring(i, i+4) == "&gt;") {
                sb.append('>')
                i += 4
            }
            else if(i + 4 <= text.length && text.substring(i, i+4) == "&lt;") {
                sb.append('<')
                i += 4
            }
            else if(i + 7 <= text.length && text.substring(i, i+7) == "&frasl;") {
                sb.append('/')
                i += 7
            }
            else {
                sb.append(text[i])
                i++
            }
        }
        return  sb.toString()
    }
}
