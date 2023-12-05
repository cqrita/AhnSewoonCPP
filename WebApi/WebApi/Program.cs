using Microsoft.EntityFrameworkCore;
using WebApi.Data;

namespace WebApi
{
    public class Program
    {
        public static void Main(string[] args)
        {
            //WebApplication 만들기위한 가장 기초적인 함수  (CREATE)
            var builder = WebApplication.CreateBuilder(args);

            //만든애들에 여러가지 서비스 추가
            //Controller, 
            //EndPoint,
            //Swagger
            // -> API 통신을 확인하기위해 만들어진 라이브러리
            builder.Services.AddControllers();
            builder.Services.AddEndpointsApiExplorer();
            builder.Services.AddSwaggerGen();


            var connectionString = builder.Configuration.GetConnectionString("SBS_Study");
            builder.Services.AddDbContext<Context>(options => options.UseMySql(connectionString, ServerVersion.AutoDetect(connectionString)));


            //실행하기위한 밑작업
            var app = builder.Build();

            //내가 개발모드면
            if (app.Environment.IsDevelopment())
            {
                //Swagger를 사용하겠다.
                app.UseSwagger();
                app.UseSwaggerUI();
            }

            //https옵션에대한 추가1
            app.UseHttpsRedirection();
            //https 옵션에대한 추가2
            app.UseAuthorization();

            //라우트 매핑
            app.MapControllers();


            //실행
            app.Run();
        }
    }
}
