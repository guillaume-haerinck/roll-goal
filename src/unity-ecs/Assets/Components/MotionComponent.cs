using UnityEngine;
using Unity.Entities;
using Unity.Mathematics;

[GenerateAuthoringComponent]
public struct MotionComponent : IComponentData
{
    public float speed;
    public float3 direction;
}
