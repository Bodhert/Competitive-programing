defmodule Solution do

    def generate_interval(lower_bound, upper_bound) do
        Stream.iterate(lower_bound, &(&1 + 0.001)) |> Enum.take_while(fn num -> num <= upper_bound end)
    end

    def evaluate_polinomial(polinomial, x) do
        Enum.reduce(polinomial, 0, fn {a,b}, acc -> acc + (a * :math.pow(x,b)) end)
    end

    def evaluate_polinomial_revolution(polinomial, x) do
      first = Enum.map(polinomial, fn {a,b} ->  a * :math.pow(x,b) end)
      second = first

      Enum.map(first, fn num -> Enum.map(second, fn num_2 -> num * num_2 end) |> Enum.sum end)
      |> Enum.sum

    end

    def integrate(polinomial, lower_bound, upper_bound) do
        range = generate_interval(lower_bound, upper_bound)
        partial = Enum.reduce(range, 0, fn x,acc -> acc + evaluate_polinomial(polinomial, x) end)
        partial_2 = Enum.reduce(range, 0, fn x,acc -> acc + evaluate_polinomial_revolution(polinomial, x) end) * :math.pi

        dx = (upper_bound - lower_bound) / length(range)
        { dx * partial, dx * partial_2}
    end

    def main() do
        a_values = IO.gets("") |> String.split() |> Enum.map(&String.to_integer(&1))
        b_values = IO.gets("") |> String.split() |> Enum.map(&String.to_integer(&1))
        [lower_bound | rest] = IO.gets("") |> String.split() |> Enum.map(&String.to_integer(&1))
        [upper_bound | _ ] = rest

        polinomial = Enum.zip(a_values,b_values)
        {first_result, second_result} = integrate(polinomial, lower_bound, upper_bound)

        IO.puts(first_result)

        IO.puts(second_result)

    end
  end

  Solution.main
