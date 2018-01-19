using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using NUnit.Framework;

namespace TriangleSpaceSharp
{
    class Program
    {
        static void Main(string[] args)
        {
            
                Assert.True(new RectangularSpace(3, 4, 5).GetSpace() == 6);                        //прямоугольный треугольник 
                Assert.Throws<ArgumentException>(()=>new RectangularSpace(3,4,6).GetSpace());      //попытка создать непавильный треугольник, вываливаем исключение типа "argument exception"
                Assert.Throws<ArgumentOutOfRangeException>(() => new RectangularSpace(-3, 4, 8).GetSpace()); //не корректные параметры, вываливаем "out of range exception"                                 

                Console.Write("all test is completed!");
                Console.ReadKey();
        }
    }

    //Интерфейс, согласно которому должен быть реализован метод подсчета площади в треугольниках
    interface ISpace
    {
         Double GetSpace();
    }
    
    //Класс треугольника
    class Triangle : ISpace
    {
        public Triangle(double a, double b, double c)
        {
            //1.1 Проверим корректность переданных параметров (строго больше 0)
            if (a <= 0 || b <= 0 || c <=0 )
                throw new ArgumentOutOfRangeException("переданные параметры должны быть > 0");
        
            //1.2 Проверим, что переданные параметры составляют стороны прямоугольника по аксиоме:
	        //"Любая сторона треугольника меньше суммы двух других сторон и больше их разности"
            if ((a > (b + c) || b > (a + c) || c > (a + b)) || (a < Math.Abs(b - c) || b < Math.Abs(a - c) || c < Math.Abs(a - b)))
		        throw new ArgumentOutOfRangeException("переданные параметры не являются сторонами треугольника");

            this.a = a;
            this.b = b;
            this.c = c;

        }

        //реализация интерфейса ISpace
        public Double GetSpace()
        {
            //условно не реализован
            return 0; 
        }


        //стороны треугольника
        public double a {get; private set;}
        public double b {get; private set;}
        public double c {get; private set;}
    }
    
   //Класс прямоугольного треугольника
   class RectangularSpace : Triangle
   {

       public RectangularSpace(double a, double b, double c) : base(a,b,c)
       {
           //2.1.Найдем максимальный параметр из переданных, это - гипотенуза, а остальные - катеты. 
           _hippo = Math.Max(Math.Max(a,b),c);

           if (b < _hippo && c < _hippo)//если max = a
           {
               _katet1 = b;
               _katet2 = c;
           }
           if (a < _hippo && c < _hippo) //если max = b
           {
               _katet1 = a;
               _katet2 = c;
           }
           else //иначе max = c
           {
               _katet1 = a;
               _katet2 = b;
           }
           
           //2.2 Теорема Пифагора. В прямоугольном треугольнике квадрат гипотенузы равен сумме квадратов катетов:
           if (Math.Pow(_hippo,2) != Math.Pow(_katet1,2) + Math.Pow(_katet2,2))
           {
               throw new ArgumentException("переданные параметры не являются сторонами прямоугольного треугольника");
           }

       }

       private double _hippo;
       private double _katet1;
       private double _katet2;

       public new double GetSpace()
       {
           return (_katet1 * _katet2) / 2;         
       }
   
   }

}
