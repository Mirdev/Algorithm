import numpy as np
import random
import time
    
def feedback(guess, real):
    strike = 0
    
    g_remain = []
    r_remain = []
    for g, r in zip(guess, real):
        if g == r:
            strike += 1
        else:
            g_remain.append(g)
            r_remain.append(r)
    
    ball = 0
    for g in g_remain:
        if g in r_remain:
            ball += 1
            r_remain.remove(g)
    
    return strike, ball

def entropy_of_guess(guess, candidates):
    dist = {}
    for theta in candidates:
        sb = feedback(guess, theta)
        dist[sb] = dist.get(sb, 0) + 1
        
    total = len(candidates)
    entropy = 0
    
    for count in dist.values():
        p = count / total
        entropy -= p * np.log2(p)
        
    worst_case = max(dist.values())
    
    return entropy, worst_case

def choose_guess(candidates):
    best_guess, best_entropy, best_worst_case = None, -1, 10001
    
    for guess in candidates:
        entropy, worst_case = entropy_of_guess(guess, candidates)
        if entropy > best_entropy or (entropy == best_entropy and worst_case < best_worst_case):
            best_entropy, best_worst_case, best_guess = entropy, worst_case, guess
    return best_guess

candidates = [f'{c:04d}' for c in range(10000)]

# real_answer = str(random.randint(0, 9999)).zfill(4)
# real_answer = "9911"

turn = 1

while candidates:
    start = time.time()
    
    if turn == 1:
        guess = "0123"
    else:
        print("Thinking...")
        guess = choose_guess(candidates)
    
    print(f"Turn {turn}: candidates={len(candidates)}, guess={guess}, execution_time={time.time()-start:.5f}s")
    
    user_input = input("Enter the number of strikes and balls without spaces (e.g., 11): ")
    observed_feedback = tuple(int(c) for c in user_input)
#     observed_feedback = feedback(guess, real_answer)
#     print(f"Turn {turn}: candidates={len(candidates)}, guess={guess}, feedback={observed_feedback}, execution_time={time.time()-start:.5f}s")
    
    if observed_feedback == (4,0) or len(candidates)==1:
        print(f"Correct answer ({guess}) found!")
        break
    elif turn > 8:
        print("Game over!")
        break
        
    start = time.time()

    candidates = [c for c in candidates if feedback(guess, c) == observed_feedback]
    turn += 1
