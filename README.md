#   Rule Book of Sokoban in Time Maze
STM 游戏规则书

（注：本项目基于mac系统开发，Windows可体验Sokoban文件夹中的极简基础逻辑版本）

一、迷宫地图（Maze’s Map）
迷宫地图由不超过 10*10 的格子组成，这些格子上会被放置各种对象（Object）。并且，
地图边界的一圈格子必须被放置固定箱或逃生点。每张地图有且仅有一个角色（PC）、
一个逃生点（Escape Point），至少存在一个箱子（Box）、一个安定点（Safe Point）。
每张地图的初始状态下，一个格子上至多存在一个对象。

二、对象（Objects）
1. 角色（PC）：受玩家（Player）操控的角色，会占据（Occupy）一个格子。
2. 箱子（Box）：可交互对象，会占据一个格子。可以被推动（Push）。
3. 固定箱（Fixed Box）：不可交互对象，会占据一个格子。作为地图的边界/障碍物。
4. 安定点（Safe Point）：不可交互对象，不会占据格子。占据安定点所在格子的对象
获得安定（Safe）状态，离开时移除该状态。
5. 逃生点（Escape Point）：不可交互对象，会占据一个格子。角色向逃生点移动视为
逃生，通过关卡。
6. 传送门（Portal）：可交互对象，不会占据格子。成对出现。
   
三、玩家操作说明（Player’s Operation Instructions）
1. WASD：令角色进行移动或推动箱子。
2. T：进行时间回溯（Time Reverse）。
3. 空格（Space）：与传送门交互，使角色移动到成对的另一个传送门上。
4. 提示（Hint）：鼠标点击，提供预设的提示。
5. 时空乱流（Spatio-Temporal Chaos）：通过该关卡后可解锁，玩家点击后，随机移动
场上除了固定箱和逃生点之外的所有对象，且经程序验证必定有解。此时原有的提示
按钮变更为推演（Deduction），玩家可以使用推演获得帮助，程序将逐步呈现验证过
的解法。
6. 下一关（Next Level）：通过该关卡后可解锁，玩家点击后，加载下一关。若当前是
最后一关，按钮变更为通关（Clear）。
7. 重新开始（Restart）：点击后关卡重新加载。
   
四、机制（Mechanisms）
1. 占据（Occupy）：角色、箱子、固定箱、逃生点这四类对象会占据所处的格子。任
何格子，最多被一个对象占据。
2. 移动（Move）：在角色四周（上下左右）的某个格子未被占据时，玩家可以操控角
色向这个格子移动，并占据这个格子。存在逃生（Escape）和传送（Teleport）两种特
殊的移动方式。
3. 逃生（Escape）：一种特殊的移动。若角色四周的某个格子已被占据，当且仅当格
子被逃生点占据时，角色可以向该格子移动，这将被视为逃生。执行逃生后的角色不
会占据任何格子，逐渐淡化消失，同时玩家通过关卡。
4. 推动箱子（Push）：当角色在某个箱子四周，玩家可以沿角色-->箱子的方向，尝试
将箱子推动一格。若目标格被占据，则推动不生效；若目标格未被占据，箱子被推动
到目标格，玩家移动至箱子原本的位置。
5. 时间回溯（Time Reverse）：玩家点击时间回溯按钮，使所有不在安定点上（不处于
安定状态）的玩家和箱子回到关卡开始时的位置。每一关的时间回溯次数有限，关卡
界面上会显示剩余次数。
6. 传送（Teleport）：一种特殊的移动。当角色位于传送门上，玩家可以按下空格与传
送门交互，使角色移动到成对的另一个传送门上。箱子不会与传送门交互。传送并不
会影响角色在关卡中的初始位置，不会对时间回溯机制造成影响。
