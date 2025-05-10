using UltraDES;
using UltraDES.Diagnosability;
using UltraDES.Opacity;

class Program
{
    static void Main(string[] args)
    {
        var motor = CriarMotor();
        var andares = CriarAndares();
        var especificacao_max = CriarEspecificacaoProibirSubidaDo4();
        var especificacao_min = CriarEspecificacaoProibirDescerDo1();

        var Planta = motor.ParallelCompositionWith(andares);
        var Especificacao = especificacao_max.ParallelCompositionWith(especificacao_min);
        //var composicaoParalela = Planta.ParallelCompositionWith(Especificacao);

        var Supervisor = DeterministicFiniteAutomaton.MonolithicSupervisor(
            new[] { motor, andares },
            new[] { especificacao_max, especificacao_min },
            true);

        motor.ShowAutomaton("Motor");
        andares.ShowAutomaton("Andares");
        especificacao_max.ShowAutomaton("Especificacao_Seguranca_AndarMaximo4");
        especificacao_min.ShowAutomaton("Especificacao_Seguranca_AndarMinimo1");

        Planta.ShowAutomaton("Elevador");
        Especificacao.ShowAutomaton("Especificacao");
        Supervisor.ShowAutomaton("Supervisor-Monolitico");
    }

    // Função que cria o autômato do motor (subir, descer, parar)
    static DeterministicFiniteAutomaton CriarMotor()
    {
        var P = new State("P", Marking.Marked);
        var S = new State("S", Marking.Unmarked);
        var D = new State("D", Marking.Unmarked);

        var s = new Event("s", Controllability.Controllable);
        var d = new Event("d", Controllability.Controllable);
        var p = new Event("p", Controllability.Controllable);

        var transicoes = new[]
        {
            new Transition(P, s, S),
            new Transition(S, p, P),
            new Transition(P, d, D),
            new Transition(D, p, P),
            new Transition(D,d,D),
            new Transition(S,s,S),
            new Transition(P,p,P)
        };

        var motor = new DeterministicFiniteAutomaton(transicoes, P, "Motor");
        motor.ShowAutomaton("Motor");
        return motor;
    }

    // Função que cria o autômato dos andares (1 a 4)
    static DeterministicFiniteAutomaton CriarAndares()
    {
        var andar1 = new State("1", Marking.Marked);
        var andar2 = new State("2", Marking.Marked);
        var andar3 = new State("3", Marking.Marked);
        var andar4 = new State("4", Marking.Marked);

        var s_1 = new Event("s_1", Controllability.Uncontrollable); 
        var s_2 = new Event("s_2", Controllability.Uncontrollable); 
        var s_3 = new Event("s_3", Controllability.Uncontrollable);
        var s_4 = new Event("s_4", Controllability.Uncontrollable); 

        var transicoes = new[]
        {
            new Transition(andar1, s_1, andar1),
            new Transition(andar1, s_2, andar2),
            new Transition(andar2, s_2, andar2),
            new Transition(andar2, s_1, andar1),
            new Transition(andar2, s_3, andar3),
            new Transition(andar3, s_3, andar3),
            new Transition(andar3, s_2, andar2),
            new Transition(andar3, s_4, andar4),
            new Transition(andar4, s_4, andar4),
            new Transition(andar4, s_3, andar3)
        };

        var automaton = new DeterministicFiniteAutomaton(transicoes, andar1, "Andares");

        return automaton;
    }

    static DeterministicFiniteAutomaton CriarEspecificacaoProibirSubidaDo4()
    {
        // Estados
        var j = new State("~4", Marking.Marked); // não é o andar 4
        var andar4 = new State("4", Marking.Marked);

        var s_1 = new Event("s_1", Controllability.Uncontrollable);
        var s_2 = new Event("s_2", Controllability.Uncontrollable);
        var s_3 = new Event("s_3", Controllability.Uncontrollable);
        var s_4 = new Event("s_4", Controllability.Uncontrollable);
        var s = new Event("s", Controllability.Controllable);
        var d = new Event("d", Controllability.Controllable);
        var p = new Event("p", Controllability.Controllable);

        var transicoes = new[]
        {
            new Transition(j, s_4, andar4),
            new Transition(j, s_1, j),
            new Transition(j, s_2, j),
            new Transition(j, s_3, j),
            new Transition(j, s, j),
            new Transition(andar4, s_4, andar4),
            new Transition(andar4, s_3, j),
            new Transition(andar4, s_2, j),
            new Transition(andar4, s_1, j),
        };

        var e1 = new DeterministicFiniteAutomaton(transicoes, j, "Especificacao_Seguranca_AndarMaximo4");
        return e1;
    }

    static DeterministicFiniteAutomaton CriarEspecificacaoProibirDescerDo1()
    {
        // Estados
        var j = new State("~1", Marking.Marked); // onde i ∈ {1,2,3}
        var andar1 = new State("1", Marking.Marked);

        var s_1 = new Event("s_1", Controllability.Uncontrollable);
        var s_2 = new Event("s_2", Controllability.Uncontrollable);
        var s_3 = new Event("s_3", Controllability.Uncontrollable);
        var s_4 = new Event("s_4", Controllability.Uncontrollable);
        var s = new Event("s", Controllability.Controllable);
        var d = new Event("d", Controllability.Controllable);
        var p = new Event("p", Controllability.Controllable);

        var transicoes = new[]
        {
            new Transition(j, s_1, andar1),
            new Transition(j, s_4, j),
            new Transition(j, s_2, j),
            new Transition(j, s_3, j),
            new Transition(j, d, j),
            new Transition(andar1, s_1, andar1),
            new Transition(andar1, s_3, j),
            new Transition(andar1, s_2, j),
            new Transition(andar1, s_4, j),
        };

        var e1 = new DeterministicFiniteAutomaton(transicoes, andar1, "Especificacao_Seguranca_AndarMinimo1");
        return e1;
    }


    // Função que cria o autômato da porta (aberta, fechada)
    static DeterministicFiniteAutomaton CriarPlantaPorta()
    {
        var Fechada = new State("FECHADA", Marking.Marked);
        var Aberta = new State("ABERTA", Marking.Unmarked);

        var abrir = new Event("abrir_porta", Controllability.Controllable);
        var fechar = new Event("fechar_porta", Controllability.Uncontrollable);

        var transicoes = new[]
        {
            new Transition(Fechada, abrir, Aberta),
            new Transition(Aberta, fechar, Fechada),
            new Transition(Aberta, abrir, Aberta),
            new Transition(Fechada, fechar, Fechada)
        };

        var Porta = new DeterministicFiniteAutomaton(transicoes, Fechada, "Porta");
        //Porta.ShowAutomaton("Porta");
        return Porta;
    }

    // Função que cria a Especificação que só pode mover o elevador com a porta fechada
    static DeterministicFiniteAutomaton CriarEspecificacaoPortaFechadaSubir()
    {
        var Fechada = new State("FECHADA", Marking.Marked);
        var Aberta = new State("ABERTA", Marking.Unmarked);

        var abrir = new Event("abrir_porta", Controllability.Controllable);
        var fechar = new Event("fechar_porta", Controllability.Uncontrollable);
        var s = new Event("subir", Controllability.Controllable);
        var d = new Event("descer", Controllability.Controllable);

        var transicoes = new[]
        {
            new Transition(Fechada, abrir, Aberta),
            new Transition(Aberta, fechar, Fechada),
            new Transition(Aberta, abrir, Aberta),
            new Transition(Fechada, s, Fechada),
            new Transition(Fechada, d, Fechada),
            new Transition(Fechada, fechar, Fechada)
        };

        var Porta = new DeterministicFiniteAutomaton(transicoes, Fechada, "Porta_e1");
        //Porta.ShowAutomaton("Porta_e1");
        return Porta;
    }

    // Função que cria a Especificação que só pode abrir a porta quando o elevador estiver parado
    static DeterministicFiniteAutomaton CriarEspecificacaoAbrirPorta()
    {
        var Parado = new State("PARADO", Marking.Marked);
        var Movendo = new State("MOVENDO", Marking.Unmarked);

        var abrir = new Event("abrir_porta", Controllability.Controllable);
        var fechar = new Event("fechar_porta", Controllability.Uncontrollable);
        var s = new Event("subir", Controllability.Controllable);
        var d = new Event("descer", Controllability.Controllable);
        var p = new Event("parar", Controllability.Controllable);

        var transicoes = new[]
        {
            new Transition(Parado, abrir, Parado),
            new Transition(Parado, d, Movendo),
            new Transition(Parado, s, Movendo),
            new Transition(Movendo, p, Parado),
            new Transition(Parado, p, Parado),
            new Transition(Movendo, d, Movendo),
            new Transition(Movendo, s, Movendo),
        };

        var Porta = new DeterministicFiniteAutomaton(transicoes, Parado, "Porta_e2");
        //Porta.ShowAutomaton("Porta_e2");
        return Porta;
    }

}
