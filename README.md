# ObstacleAssault
This is a 3D platformer game created in Unreal Engine 5 as part of the [Unreal Engine 5 C++ Developer: Learn C++ & Make Video Games course](https://www.udemy.com/course/unrealcourse/).
The game features a level with different moving and rotating platforms and obstacles that the player must navigate to reach the goal.

## Key Features
- **Dynamic Moving Platforms**: Configurable linear movement with customizable velocity, maximum distance, and optional turnaround pauses to prevent platform overshoot/drift.
- **Continuous Rotation**: Independent angular velocity per axis for rotating obstacles.
- **Blueprint Integration**: Base C++ platform classes exposed to Unreal Blueprints with categorized property controls.

## MovingPlatform Properties
| Property | Type | Description |
| :--- | :--- | :--- |
| `MoveVelocity` | `FVector` | Linear speed and movement direction vector. |
| `MaxMoveDistance` | `float` | Distance the platform travels before reversing direction. |
| `RotationVelocity` | `FRotator` | Angular rotation speed (Pitch, Yaw, Roll). |
| `bPauseAtTurnaround` | `bool` | Enables a brief pause when reaching each movement boundary. |
| `TurnaroundWaitTime` | `float` | Duration in seconds to wait at turnaround points. |

## Level Demo
https://github.com/denyskryvytskyi/ObstacleAssault/assets/25298585/ee60ee5f-bb9e-4b4f-8600-49f21d176eda

https://github.com/denyskryvytskyi/ObstacleAssault/assets/25298585/f87429aa-33ce-4ebe-8fa2-4f32201184e4

https://github.com/denyskryvytskyi/ObstacleAssault/assets/25298585/2bc13386-55e6-4d02-8ec5-32c326fa1679

https://github.com/denyskryvytskyi/ObstacleAssault/assets/25298585/d46d6242-be6e-4323-a387-84397c372c50

## Getting Started
*Engine Version: Unreal Engine 5.4.1*

1. Clone the repository:
   ```bash
   git clone https://github.com/Madhumithats17/ObstacleAssult.git
   ```
2. Double-click `ObstacleAssault.uproject` to open the project in Unreal Editor.
3. Build the solution in Visual Studio or your preferred IDE if prompted.