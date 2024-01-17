# check50 cs50/problems/2023/x/sentimental/readability
# submit50 cs50/problems/2023/x/sentimental/readability

text = input("Text: ")

letters, words, sentences = 0, 1, 0  # words = 1: because spaces " " are between words and not at the beginning and end of the text.

for i in range(len(text)):
   if text[i].isalpha():
      letters += 1
   elif text[i].isspace():
      words += 1
   elif text[i] in ['.', '!', '?']:
      sentences += 1

l = (letters / words) * 100
s = (sentences / words) * 100
index = round(0.0588 * l - 0.296 * s - 15.8)

if index < 1:
   print("Before Grade 1")
elif index > 16:
   print("Grade 16+")
else:
   print(f"Grade {index}")