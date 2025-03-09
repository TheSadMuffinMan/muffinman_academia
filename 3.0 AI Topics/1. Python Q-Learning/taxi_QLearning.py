import gymnasium as gym
import numpy as np
import random
import time
from tqdm import tqdm

env = gym.make("Taxi-v3", render_mode = "ansi")

state_size = env.observation_space.n
action_size = env.action_space.n
q_table = np.zeros((state_size, action_size))

learning_rate = 0.1
discount_factor = 0.99
epsilon = 1.0
epsilon_decay = 0.995
min_epsilon = 0.01
episodes = 5000

for episode in tqdm(range(episodes), desc = "Training Progress"):
    state, _ = env.reset()
    done = False

    while not done:
        if random.uniform(0,1) < epsilon:
            action = env.action_space.sample()
        else:
            action = np.argmax(q_table[state])
        
        next_state, reward, done, _, _ = env.step(action)

        q_table[state, action] = q_table[state, action] + learning_rate * (
            reward + discount_factor * np.max(q_table[next_state]) - q_table[state, action]
        )

        state = next_state

    epsilon = max(min_epsilon, epsilon * epsilon_decay)

print("\nTraining completed!")
np.save("q_table_taxi.npy", q_table)

state, _ = env.reset()
done = False
total_rewards = 0

print("\nTesting the trained agent...")
time.sleep(2)

while not done:
    action = np.argmax(q_table[state])
    state, reward, done, _, _ = env.step(action)
    total_rewards += reward
    env.render()
    time.sleep(0.5)

print("\nTotal Rewards: ", total_rewards)
env.close()