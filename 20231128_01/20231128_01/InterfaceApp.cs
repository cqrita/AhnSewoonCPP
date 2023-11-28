using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _20231128_01
{
    public interface IComponent
    {
        public void Init();
        public void Release();
        public void Update();
        public void Render();
    }
    public class CameraComponent : IComponent
    {
        public void Dispose()
        {
        }

        public void Init()
        {
        }

        public void Release()
        {
        }

        public void Render()
        {
        }

        public void Update()
        {
        }
    }
    public class InterfaceApp
    {
        public void Run()
        {
            List<IComponent> list = new List<IComponent>();
            foreach (IComponent component in list)
            {
                component.Init();
            }
        }
    }
}
