from collections import Counter

class Solution:
    def shortestCompletingWord(self, licensePlate: str, words: list[str]) -> str:
        target_counts = Counter(ch.lower() for ch in licensePlate if ch.isalpha())
        
        best_word = ""
        for word in words:
            word_counts = Counter(word)
            if not (target_counts - word_counts):
                if not best_word or len(word) < len(best_word):
                    best_word = word
                    
        return best_word
