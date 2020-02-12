using UnityEngine;
using Unity.Entities;

[GenerateAuthoringComponent]
public struct InputComponent : IComponentData
{
    public KeyCode forwardKey;
    public KeyCode leftKey;
    public KeyCode rightKey;
    public KeyCode backKey;
}
