
import numpy as np
import matplotlib.pyplot as plt
import pandas as pd
my_csv = pd.read_csv("tvlapoints.csv")
t_score = my_csv.iloc[:, 0].values

fig, ax = plt.subplots()
            
ax.plot(t_score, marker='.', color='blue')
#plt.plot([0, 140], [4.5,4.5], color='red', label='threshold')
#plt.plot([0, 140], [-4.5,-4.5], color='red')
    
ax.set_xlim([0,120])
ax.set_ylim([-1.5,1.5])
plt.xlabel("Trace Points", fontsize=14, fontweight='bold')
plt.ylabel("T scores", fontsize=14, fontweight='bold')
plt.legend(prop=dict(weight='bold',size=12))
plt.xticks(fontsize=12, fontweight='bold')
plt.yticks(fontsize=12, fontweight='bold')
plt.savefig('tvla_lbt_full.pdf', dpi=1200)
plt.show()
