import random
from collections import Counter
import time

candidates = []
for i in range(0, 10000): # no reading zero => range(1234, 9877)
    s = str(i).zfill(4)
    if len(set(s)) == 4: # no duplicates
        candidates.append(s)

def feedback(guess, answer):
    strikes = sum(g == a for g, a in zip(guess, answer))
    balls = sum(min(guess.count(d), answer.count(d)) for d in set(guess)) - strikes
    return strikes, balls

def update_distribution(candidates):
    position_probs = [Counter() for _ in range(4)]
    for c in candidates:
        for i, digit in enumerate(c):
            position_probs[i][digit] += 1
    return position_probs

# For debug
# real_answer = random.choice(candidates)
# real_answer = "7832"
# print("Answer(for debug):", real_answer)

turn = 1
while True:
    start = time.time()
    position_probs = update_distribution(candidates)
    
    guess = ''.join(max(position_probs[i].items(), key=lambda x: x[1])[0] for i in range(4))

    if len(set(guess)) < 4 or guess not in candidates:
        guess = random.choice(candidates)
    
### user interaction
    print(f"Turn {turn}: guess={guess}, candidates={len(candidates)}, execution_time={time.time()-start:.5f}s")
    
    user_input = input("Enter the number of strikes and balls without spaces (e.g., 11): ")
    observed_feedback = tuple(int(c) for c in user_input)

### self validation
#     observed_feedback = feedback(guess, real_answer)
#     print(f"Turn {turn}: guess={guess}, candidates={len(candidates)}, feedback={observed_feedback}, execution_time={time.time()-start:.5f}s")
###

    if observed_feedback == (4,0) or len(candidates)==1:
        print(f"Correct answer ({guess}) found!")
        break
    elif turn > 8:
        print("Game over!")
        break

    candidates = [c for c in candidates if feedback(guess, c) == observed_feedback]
    if not candidates:
        print("Cannot find the number!")
        break
    turn += 1
