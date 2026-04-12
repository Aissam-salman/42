/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sample.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 11:11:15 by alamjada          #+#    #+#             */
/*   Updated: 2026/04/12 11:34:56 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SAMPLE_HPP
# define SAMPLE_HPP

class Sample {
    public:
        Sample(void);
        ~Sample(void);

        void bar(char const c) const;
        void bar(int const n) const;
        void bar(float const z) const;
        void bar(Sample const & i) const;
};

#endif
